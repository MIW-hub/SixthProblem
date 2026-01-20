// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorMovement.h"

// Sets default values
AActorMovement::AActorMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

