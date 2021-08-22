// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class MYGAME_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractable();

	bool CanBePickedUp() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UItemBase* InventoryComponent;

	UFUNCTION(BlueprintCallable, Category = "Interact")
	FString GetUseActionText() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere)
	bool bCanBePickedUp = false;
};
