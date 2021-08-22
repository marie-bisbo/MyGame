// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantBase.h"
#include "HealthItem.h"

APlantBase::APlantBase()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	bCanBePickedUp = true;
}

