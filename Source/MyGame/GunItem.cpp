// Fill out your copyright notice in the Description page of Project Settings.


#include "GunItem.h"
#include "LineTrace.h"
#include "CharacterBase.h"
#include "GunBase.h"
#include "InventoryComponent.h"
#include "Kismet/GameplayStatics.h"

void UGunItem::Use(ACharacterBase* Character)
{
	Character->EquipItem(this);
}

void UGunItem::SpawnInWorld()
{
	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	Gun = GetWorld()->SpawnActor<AGunBase>(GunClass);
	Character->GetMesh()->HideBoneByName(TEXT("joint1"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("armSocket"));
	Gun->SetOwner(Character);
}

void UGunItem::UseEquiped()
{
	if (Gun)
		Gun->FireGun();
}
