// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (RootComponent)
	{
		RootComponent->SetMobility(EComponentMobility::Movable);
	}
}

// Called when the game starts or when spawned
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	MoveDirection = GetActorForwardVector();
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f)); // - pitch,yaw,roll
	SetActorScale3D(FVector(1.0f, 1.0f, 0.2f));
}

// Called every frame
void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentLocation = GetActorLocation();

	FVector NextLocation = CurrentLocation + (MoveDirection * MoveSpeed * DeltaTime);

	float Dist = FVector::Dist(NextLocation, StartLocation);

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		AddActorWorldOffset(MoveDirection * MoveSpeed * DeltaTime);
	}
	if (!Returning && Dist > MaxRange) {
		MoveDirection = -MoveDirection;
		Returning = true;
		UE_LOG(LogTemp, Warning, TEXT("Is Returning: %s"), Returning ? TEXT("True") : TEXT("False"));
	}
	else if (Returning && Dist < MinRange) {
		MoveDirection = -MoveDirection;
		Returning = false;
		UE_LOG(LogTemp, Warning, TEXT("Is Returning: %s"), Returning ? TEXT("True") : TEXT("False"));
	}
	if (GEngine)
	{
		FString DebugMsg = FString::Printf(TEXT("Distance: %f / Dir: %s"), Dist, *MoveDirection.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, DebugMsg);
	}
}

// Called to bind functionality to input
void AMoveActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

