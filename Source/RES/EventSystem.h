// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EventSubscriber.h"
#include "CoreMinimal.h"
#include "EventSystem.generated.h"

DECLARE_DYNAMIC_DELEGATE(FEventDelegate);

USTRUCT(BlueprintType)
struct FEventSubscription
{
	GENERATED_BODY()

	UPROPERTY()
	TWeakObjectPtr<UObject> Subscriber;

	UPROPERTY()
	FEventDelegate Delegate;

	FEventSubscription()
	{
	}

	FEventSubscription(UObject* InSubscriber, FEventDelegate InDelegate)
		: Subscriber(InSubscriber), Delegate(InDelegate)
	{
	}
};


/**
 * 
 */
class RES_API EventSystem
{
public:
	EventSystem();
	~EventSystem();

	
	TMap<FName, TArray<FEventSubscription>> NameToSubscriber;
};
