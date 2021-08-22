// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyGamePlayerController.generated.h"

UCLASS()
class MYGAME_API AMyGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class AInteractable* CurrentInteractable = nullptr;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;
};
