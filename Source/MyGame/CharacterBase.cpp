// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GunItem.h" 
#include "ItemBase.h"
#include "ConsumableItem.h"
#include "EquipableItem.h"
#include "InventoryComponent.h"
#include "LineTrace.h"
#include "GunBase.h"
#include "Interactable.h"
#include "LineTrace.h"
#include "MyGamePlayerController.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm"));
	SpringArm->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	DetectionTrace = CreateDefaultSubobject<ULineTrace>(TEXT("DetectionTrace"));
	DetectionTrace->SetRange(DetectionRange);

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	Inventory->SetCapacity(20);
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	bItemEquiped = false;
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DetectInteractables();

	if (!bProtectedFromEnvironment)
		DecreaseHealthOverTime(DeltaTime);
}

void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACharacterBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACharacterBase::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ACharacterBase::UseEquipedItem);
	PlayerInputComponent->BindAction(TEXT("Interact"), IE_Pressed, this, &ACharacterBase::PickUpItem);
}

void ACharacterBase::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ACharacterBase::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

FLineTraceResult ACharacterBase::DetectInteractables()
{
	FLineTraceResult HitResult = DetectionTrace->GetLineTraceResult();
	AMyGamePlayerController* PlayerController = Cast<AMyGamePlayerController>(GetController());

	if (!PlayerController)
		return HitResult;

	if (AInteractable* Interactable = Cast<AInteractable>(HitResult.Hit.GetActor()))
	{
		PlayerController->CurrentInteractable = Interactable;
	}
	else
	{
		PlayerController->CurrentInteractable = nullptr;
	}

	return HitResult;
}

void ACharacterBase::PickUpItem()
{
	UObject* ItemDetected = DetectInteractables().Hit.GetComponent();
	AInteractable* InteractableDetected = Cast<AInteractable>(DetectInteractables().Hit.GetActor());
	bool bInteractableDetected = DetectInteractables().bHitSuccessful && InteractableDetected;

	if (!bInteractableDetected && InteractableDetected->CanBePickedUp()) return;

	if (InteractableDetected && InteractableDetected->CanBePickedUp())
	{
		Inventory->AddItem(InteractableDetected->InventoryEntry);
		InteractableDetected->Destroy();
	}
}

void ACharacterBase::UseEquipedItem()
{
	if (bItemEquiped && CurrentEquipedItem)
		CurrentEquipedItem->UseEquiped();
}

void ACharacterBase::DecreaseHealthOverTime(float DeltaTime)
{
	CurrentHealth -= 0.3 * DeltaTime;
}

void ACharacterBase::ChangeCurrentHealth(float Amount)
{
	CurrentHealth = FMath::Min(MaxHealth, CurrentHealth += Amount);
}

bool ACharacterBase::GetProtectedFromEnvironment() const
{
	return bProtectedFromEnvironment;
}

void ACharacterBase::SetProtectedFromEnvironment(bool bIsProtected)
{
	bProtectedFromEnvironment = bIsProtected;
}

float ACharacterBase::GetCurrentHealth() const
{
	return CurrentHealth;
}

float ACharacterBase::GetMaxHealth() const
{
	return MaxHealth;
}

float ACharacterBase::GetHealthPercentage() const
{
	return CurrentHealth / MaxHealth;
}

// Gets called in BP
void ACharacterBase::UseItem(UItemBase* Item)
{
	if (!Item) return;

	Item->Use(this);
	Item->OnUse(this); // BP event

	if (Item == Cast<UConsumableItem>(Item))
	{
		Inventory->RemoveItem(Item);
	}
}

void ACharacterBase::EquipItem(UEquipableItem* Item)
{
	if (!bItemEquiped)
	{
		Item->SpawnInWorld();
		bItemEquiped = true;
		CurrentEquipedItem = Item;
	}
}

void ACharacterBase::EquipSuit(UEquipableItem* Item)
{
	if (!bSuitEquiped)
	{
		bSuitEquiped = true;
		CurrentEquipedSuit = Item;
	}
}
