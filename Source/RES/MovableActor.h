// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MovableActor.generated.h"

UCLASS()
class RES_API AMovableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetCustomRotationLocks(bool XAxis, bool YAxis, bool ZAxis);

	UFUNCTION(BlueprintCallable)
	void SetIsRotationAllowed(bool IsAllowed);

	UFUNCTION(BlueprintCallable)
	void SetCustomPlaneConstrains(bool XAxis, bool YAxis, bool ZAxis);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
