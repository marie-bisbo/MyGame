// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "ItemBase.h"

AInteractable::AInteractable()
{
}

void AInteractable::BeginPlay()
{
	Super::BeginPlay();
}

bool AInteractable::CanBePickedUp() const
{
	return bCanBePickedUp;
}

FString AInteractable::GetUseActionText() const
{
	 return InventoryComponent->GetUseActionText(); 
}
