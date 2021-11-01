// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

// Blueprints will bind to this to update the UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	virtual void BeginPlay() override;

	bool AddItem(class UItemBase* Item);
	bool RemoveItem(class UItemBase* Item);

	int32 GetCapacity() const;
	void SetCapacity(int32 CapacityAmount);

	bool IsFull() const;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<class UItemBase*> Items;

private:
	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<class UItemBase*> StartItems;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 Capacity;
};
