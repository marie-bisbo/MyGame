// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "EquipableItem.generated.h"

UCLASS()
class MYGAME_API UEquipableItem : public UItemBase
{
	GENERATED_BODY()

public:
	virtual void SpawnInWorld() PURE_VIRTUAL(UEquipableItem, );
	virtual void UseEquiped() PURE_VIRTUAL(UEquipableItem, );
};
