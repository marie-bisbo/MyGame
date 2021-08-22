// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class MYGAME_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

	void EquipItem(class UEquipableItem* Item);

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ChangeCurrentHealth(float Amount);

	float GetCurrentHealth() const;

	float GetMaxHealth() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercentage() const;

	UFUNCTION(BlueprintCallable, Category = "Items")
	void UseItem(class UItemBase* Item);

protected:
	virtual void BeginPlay() override;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	struct FLineTraceResult DetectInteractables();
	void PickUpItem();
	void UseEquipedItem();
	void DecreaseHealthOverTime(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* Inventory;

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	float CurrentHealth;

	UPROPERTY(EditAnywhere)
	float DetectionRange = 200.f;
	
	UPROPERTY()
	class ULineTrace* DetectionTrace;

	UPROPERTY(VisibleAnywhere)
	bool bItemEquiped;

	UPROPERTY(VisibleAnywhere)
	class UEquipableItem* CurrentEquipedItem = nullptr;
};
