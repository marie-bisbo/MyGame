// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthItem.h"
#include "CharacterBase.h"

void UHealthItem::Use(ACharacterBase* Character)
{
	//bool bCharacterAtFullHealth = Character->GetCurrentHealth() < Character->GetMaxHealth();
	if (Character)
	{
		Character->ChangeCurrentHealth(10.f);
	}
}
