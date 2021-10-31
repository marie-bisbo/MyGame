// Fill out your copyright notice in the Description page of Project Settings.


#include "EnvironmentSuit.h"

AEnvironmentSuit::AEnvironmentSuit()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	bCanBePickedUp = true;
}
