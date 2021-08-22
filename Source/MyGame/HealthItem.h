// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConsumableItem.h"
#include "HealthItem.generated.h"

UCLASS()
class MYGAME_API UHealthItem : public UConsumableItem
{
	GENERATED_BODY()

protected:

	virtual void Use(class ACharacterBase* Character) override;
};
