// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBase.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class MYGAME_API UItemBase : public UObject
{
	GENERATED_BODY()

public:
	UItemBase();

	virtual class UWorld* GetWorld() const { return World; }

	UPROPERTY(Transient)
	class UWorld* World;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText UseActionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	class UStaticMesh* PickupMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	class UTexture2d* Thumbnail;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText ItemDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.f))
	float Weight;

	UPROPERTY()
	class UInventoryComponent* OwningInventory;

	virtual void Use(class ACharacterBase* Character) PURE_VIRTUAL(UItemBase, );

	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class ACharacterBase* Character);

	UFUNCTION(BlueprintCallable, Category = "Interact")
	FString GetUseActionText() const { return FString::Printf(TEXT("%s"), *UseActionText.ToString()); }
};
