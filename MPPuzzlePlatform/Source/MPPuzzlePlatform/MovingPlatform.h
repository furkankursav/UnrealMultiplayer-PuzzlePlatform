// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MPPUZZLEPLATFORM_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget=true))
	FVector TargetLocation;

public:

	AMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;


};
