// Fill out your copyright notice in the Description page of Project Settings.


#include "LawMonolith.h"

// Sets default values
ALawMonolith::ALawMonolith()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
}

// Called when the game starts or when spawned
void ALawMonolith::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALawMonolith::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALawMonolith::ReinterpretLaw()
{

}

