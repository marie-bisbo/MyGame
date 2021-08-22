// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LineTrace.generated.h"

USTRUCT()
struct FLineTraceResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FHitResult Hit;

	UPROPERTY()
	bool bHitSuccessful;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API ULineTrace : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULineTrace();

	FLineTraceResult GetLineTraceResult();
	void SetRange(float r);

private:
	UPROPERTY(EditAnywhere)
	float Range;
};
