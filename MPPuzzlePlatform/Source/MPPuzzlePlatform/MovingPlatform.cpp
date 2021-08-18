// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	
	SetMobility(EComponentMobility::Movable);

	Speed = 10.f;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();


	SetReplicates(true);
	SetReplicatingMovement(true);
	


}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// runs only on server.
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		FVector GlobalTargetLoc = GetTransform().TransformPosition(TargetLocation);
		FVector Direction = (GlobalTargetLoc - Location).GetSafeNormal();

		Location += Direction * Speed * DeltaTime;

		SetActorLocation(Location);
	}


}
