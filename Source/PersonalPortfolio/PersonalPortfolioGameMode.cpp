// Copyright Epic Games, Inc. All Rights Reserved.

#include "PersonalPortfolioGameMode.h"
#include "PersonalPortfolioCharacter.h"
#include "UObject/ConstructorHelpers.h"

APersonalPortfolioGameMode::APersonalPortfolioGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}
