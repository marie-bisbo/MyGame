// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "GunBase.generated.h"

UCLASS()
class MYGAME_API AGunBase : public AInteractable
{
	GENERATED_BODY()
	
public:	
	AGunBase();
	virtual void FireGun();

private:	
	UPROPERTY(EditAnywhere)
	float Range = 1000.f;

	class ULineTrace* LineTrace;

	virtual void Shoot();
	virtual void OnHit(AActor* ActorHit);
};
