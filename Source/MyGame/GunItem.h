// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EquipableItem.h"
#include "GunItem.generated.h"

UCLASS()
class MYGAME_API UGunItem : public UEquipableItem
{
	GENERATED_BODY()

public:
	void SpawnInWorld() override;
	void UseEquiped() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGunBase> GunClass;

	UPROPERTY()
	class AGunBase* Gun;

protected:
	virtual void Use(class ACharacterBase* Character) override;
};
