// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableActor.h"
#include "PhysicsEngine/BodyInstance.h"

// Sets default values
AMovableActor::AMovableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Mesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void AMovableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMovableActor::SetCustomRotationLocks(bool XAxis, bool YAxis, bool ZAxis)
{
	if (!Mesh) return;

	FBodyInstance* BodyInstance = Mesh->GetBodyInstance();
	if (!BodyInstance) return;

	BodyInstance->bLockXRotation = XAxis;
	BodyInstance->bLockYRotation = YAxis;
	BodyInstance->bLockZRotation = ZAxis;
}

void AMovableActor::SetIsRotationAllowed(bool IsAllowed)
{
	if (!Mesh) return;

	FBodyInstance* BodyInstance = Mesh->GetBodyInstance();
	if (!BodyInstance) return;

	BodyInstance->bLockXRotation = !IsAllowed;
	BodyInstance->bLockYRotation = !IsAllowed;
	BodyInstance->bLockZRotation = !IsAllowed;
}

void AMovableActor::SetCustomPlaneConstrains(bool XAxis, bool YAxis, bool ZAxis)
{
	if (!Mesh) return;

	FBodyInstance* BodyInstance = Mesh->GetBodyInstance();
	if (!BodyInstance) return;

	BodyInstance->CustomDOFPlaneNormal = FVector(XAxis, YAxis, ZAxis);

	BodyInstance->bLockXTranslation = XAxis;
	BodyInstance->bLockYTranslation = YAxis;
	BodyInstance->bLockZTranslation = ZAxis;
}

void AMovableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

