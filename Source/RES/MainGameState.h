// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EventSystem.h"
#include "MainGameState.generated.h"

/**
 * 
 */
UCLASS()
class RES_API UMainGameState : public UGameInstance
{
	GENERATED_BODY()

public:

	EventSystem EventSystem;
};
