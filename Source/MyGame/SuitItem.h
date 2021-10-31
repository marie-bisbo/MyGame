// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EquipableItem.h"
#include "SuitItem.generated.h"

UCLASS()
class MYGAME_API USuitItem : public UEquipableItem
{
	GENERATED_BODY()
	
protected:
	virtual void Use(class ACharacterBase* Character) override;
};
