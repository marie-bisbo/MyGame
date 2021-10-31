// Fill out your copyright notice in the Description page of Project Settings.


#include "SuitItem.h"
#include "CharacterBase.h"

void USuitItem::Use(ACharacterBase* Character)
{
	if (Character)
	{
		Character->EquipSuit(this);
		Character->SetProtectedFromEnvironment(true);
	}
}

