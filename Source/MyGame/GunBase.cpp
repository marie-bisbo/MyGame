// Fill out your copyright notice in the Description page of Project Settings.


#include "GunBase.h"
#include "LineTrace.h"
#include "Components/StaticMeshComponent.h"
#include "GunItem.h"

AGunBase::AGunBase()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetupAttachment(Root);

	LineTrace = CreateDefaultSubobject<ULineTrace>(TEXT("LineTrace"));
	LineTrace->SetRange(Range);

	bCanBePickedUp = true;
}

void AGunBase::OnHit(AActor* ActorHit)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor hit was: %s"), *ActorHit->GetName());
}


void AGunBase::Shoot()
{
	FLineTraceResult ShotResult = LineTrace->GetLineTraceResult();
	if (ShotResult.bHitSuccessful)
	{
		OnHit(ShotResult.Hit.GetActor());
	}
}


void AGunBase::FireGun()
{
	Shoot();
}

