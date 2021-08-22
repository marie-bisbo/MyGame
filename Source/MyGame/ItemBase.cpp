// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

UItemBase::UItemBase()
{
	Weight = 1.f;
	ItemDisplayName = FText::FromString("Item");
	UseActionText = FText::FromString("Item: Press E to pickup");
}
