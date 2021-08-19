// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MPPuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MPPUZZLEPLATFORM_API UMPPuzzlePlatformGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:

	UMPPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init() override;

};
