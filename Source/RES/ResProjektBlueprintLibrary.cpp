// Fill out your copyright notice in the Description page of Project Settings.


#include "ResProjektBlueprintLibrary.h"
#include "MainGameState.h"


void UResProjektBlueprintLibrary::SubscribeToEvent(FEventDelegate Delegate, FName Event, UObject* Subscriber)
{
    UWorld* World = GEngine->GetWorldFromContextObjectChecked(Subscriber);
    if (!World) return;

    if (Subscriber && Subscriber->GetClass()->ImplementsInterface(UEventSubscriber::StaticClass()))
    {
        UMainGameState* GameInstance = Cast<UMainGameState>(World->GetGameInstance());
        if (GameInstance)
        {
            GameInstance->EventSystem.NameToSubscriber.FindOrAdd(Event).Add(FEventSubscription(Subscriber, Delegate));
        }
    }
}

void UResProjektBlueprintLibrary::BroadcastEvent(UObject* WorldContextObject, FName Event)
{
    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    if (!World) return;

    UMainGameState* GameInstance = Cast<UMainGameState>(World->GetGameInstance());
    if (GameInstance)
    {
        if (GameInstance->EventSystem.NameToSubscriber.Contains(Event))
        {
            for (const FEventSubscription& Sub : GameInstance->EventSystem.NameToSubscriber[Event])
            {
                if (Sub.Subscriber.IsValid())
                {
                    Sub.Delegate.ExecuteIfBound();
                }
            }
        }
    }
    
}
