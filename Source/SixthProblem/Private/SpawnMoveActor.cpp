// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnMoveActor.h"
#include <MoveActor.h>

// Sets default values
ASpawnMoveActor::ASpawnMoveActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CurrentLocation = FVector::ZeroVector;
	StartLocation = FVector::ZeroVector;
	MoveDirection = FVector::ForwardVector;
	ActorRotaion = FRotator::ZeroRotator;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticComp->SetupAttachment(SceneRoot);

}

// Called when the game starts or when spawned
void ASpawnMoveActor::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(13.0f);
	RanSpeed = FMath::FRandRange(10.0f, MoveSpeed);
	RanSpin = FMath::FRandRange(10.0f, RotationSpeed);
	//SetActorLocation(FVector(0.0f, 0.0f, 60.0f)); // - x,y,z
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f)); // - pitch,yaw,roll
	SetActorScale3D(FVector(1.0f, 1.0f, 0.2f));
}

// Called every frame
void ASpawnMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpinActorA(DeltaTime);
	MoveActorA(DeltaTime);

}

void ASpawnMoveActor::SetSpeed(float InSpeed)
{
	MoveSpeed = InSpeed;
}

void ASpawnMoveActor::SetSpin(float InSpin)
{
	RotationSpeed = InSpin;
}

void ASpawnMoveActor::MoveActorA(float DeltaTime)
{

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, DeltaTime * RanSpeed * MoveSpeed));
	}
}
void ASpawnMoveActor::SpinActorA(float DeltaTime)
{

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, DeltaTime * RanSpin * RotationSpeed, 0.0f));
	}
}