// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorMovement.generated.h"
class ASpawnMoveActor;
UCLASS()
class SIXTHPROBLEM_API AActorMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	FTimerHandle MyTimerHandle;
	FTimerHandle StopTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Speed")
	float ReturnRotate = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Speed")
	float ReturnSpeed = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActor> SpawnActorA;

	FVector CurrentLocation; // 처음 시작 위치 저장용

	FRotator ActorRotaion;
	float TargetLocation = 0.0f; // 목표 지점
	bool Returning = false; // 현재 돌아오는 중인지 체크

	void SpawnActorFuntion();
	void StopSpawning();
	

	void MoveActorA(float DeltaTime);
	void SpinActorA(float DeltaTime);
};
