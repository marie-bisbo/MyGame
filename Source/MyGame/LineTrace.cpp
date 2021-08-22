// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTrace.h"
#include "Kismet/GameplayStatics.h"

ULineTrace::ULineTrace()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FLineTraceResult ULineTrace::GetLineTraceResult()
{
	FHitResult Hit;
	FVector RayDirection;

	FVector OwnerLocation;
	FRotator OwnerRotation;
	AController* OwnerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!OwnerController) return FLineTraceResult{};

	OwnerController->GetPlayerViewPoint(OwnerLocation, OwnerRotation);
	RayDirection = -OwnerRotation.Vector();

	FVector EndPoint = OwnerLocation + OwnerRotation.Vector() * Range;

	FCollisionQueryParams Paramaters;
	Paramaters.AddIgnoredActor(GetOwner());
	Paramaters.AddIgnoredActor(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	bool bHitSuccessful = GetWorld()->LineTraceSingleByChannel(Hit, OwnerLocation, EndPoint, ECollisionChannel::ECC_GameTraceChannel1, Paramaters);

	return FLineTraceResult{Hit, bHitSuccessful};
}

void ULineTrace::SetRange(float r)
{
	Range = r;
}
