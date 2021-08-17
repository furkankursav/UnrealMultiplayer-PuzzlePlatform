// Copyright Epic Games, Inc. All Rights Reserved.

#include "MPPuzzlePlatformGameMode.h"
#include "MPPuzzlePlatformCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMPPuzzlePlatformGameMode::AMPPuzzlePlatformGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
