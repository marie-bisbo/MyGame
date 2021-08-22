// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGamePlayerController.h"
#include "Blueprint/UserWidget.h"

void AMyGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* HUD = CreateWidget(this, HUDClass);
	if (HUD)
	{
		HUD->AddToViewport();
	}
}
