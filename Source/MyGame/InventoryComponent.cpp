// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "ItemBase.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	Capacity = 20;
}


void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : StartItems)
	{
		AddItem(Item);
	}
}

bool UInventoryComponent::AddItem(UItemBase* Item)
{
	if (Items.Num() >= Capacity || !Item) { return false; }

	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);
	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(UItemBase* Item)
{
	if (Item)
	{
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}

	return false;
}

int32 UInventoryComponent::GetCapacity()
{
	return Capacity;
}

void UInventoryComponent::SetCapacity(int32 CapacityAmount)
{
	Capacity = CapacityAmount;
}
