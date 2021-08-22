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
	if (InventoryComponent)
	{
		return InventoryComponent->GetUseActionText(); 
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No inventory component set"));
	}
}
