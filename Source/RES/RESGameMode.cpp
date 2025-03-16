// Copyright Epic Games, Inc. All Rights Reserved.

#include "RESGameMode.h"
#include "RESCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARESGameMode::ARESGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
