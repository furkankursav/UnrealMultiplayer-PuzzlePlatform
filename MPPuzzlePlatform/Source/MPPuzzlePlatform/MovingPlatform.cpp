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
	
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);


}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// runs only on server.
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();

		// length of all travel
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();

		// how much did we go
		float TravelledJourney = (Location - GlobalStartLocation).Size();
		
		// Swap condition
		if (TravelledJourney >= JourneyLength)
		{
			FVector TempLoc = GlobalTargetLocation;
			GlobalTargetLocation = GlobalStartLocation;
			GlobalStartLocation = TempLoc;
			TravelledJourney = 0;

			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("SWAP!"));

		}


		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

		Location += Direction * Speed * DeltaTime;

		SetActorLocation(Location);

	}


}
