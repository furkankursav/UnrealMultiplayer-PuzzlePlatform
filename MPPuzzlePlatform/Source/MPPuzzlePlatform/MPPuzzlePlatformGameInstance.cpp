// Fill out your copyright notice in the Description page of Project Settings.


#include "MPPuzzlePlatformGameInstance.h"

UMPPuzzlePlatformGameInstance::UMPPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance constructer!"));
}

void UMPPuzzlePlatformGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init!"));

}

void UMPPuzzlePlatformGameInstance::Host()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Hosting"));

	GetWorld()->ServerTravel("/Game/_Game/Levels/Level01?listen");


}

void UMPPuzzlePlatformGameInstance::Join(const FString& Address)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
}
