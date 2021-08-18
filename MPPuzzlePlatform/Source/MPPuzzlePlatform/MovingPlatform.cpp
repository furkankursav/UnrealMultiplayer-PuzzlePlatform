// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);

	Speed = 10.f;
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// runs only on server.
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();

		Location += FVector(Speed * DeltaTime, 0, 0);

		SetActorLocation(Location);
	}


}
