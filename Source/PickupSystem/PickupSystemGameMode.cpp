// Copyright Epic Games, Inc. All Rights Reserved.

#include "PickupSystemGameMode.h"
#include "PickupSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

APickupSystemGameMode::APickupSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
