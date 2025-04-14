// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EventSystem.h"
#include "ResProjektBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RES_API UResProjektBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void SubscribeToEvent(UPARAM(DisplayName = "Event") FEventDelegate Delegate, FName Event, UObject* Subscriber);

	UFUNCTION(BlueprintCallable)
	static void BroadcastEvent(UObject* WorldContextObject, FName Event);

};
