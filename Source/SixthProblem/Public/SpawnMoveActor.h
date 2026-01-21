// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnMoveActor.generated.h"

UCLASS()
class SIXTHPROBLEM_API ASpawnMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn");
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn");
	UStaticMeshComponent* StaticComp;

private:
	// Called every frame

public:
	FVector StartLocation;
	FVector CurrentLocation; // 처음 시작 위치 저장용
	FVector MoveDirection; //
	FRotator ActorRotaion;
	float TargetLocation = 0.0f; // 목표 지점
	bool Returning = false; // 현재 돌아오는 중인지 체크

	void SpinActorA(float DeltaTime);
	void SetSpin(float InSpin);
	void SetSpeed(float InSetSpeed);

	float GetSpeed() const { return MoveSpeed; }
	float GetSpin()  const { return RotationSpeed; }

	void MoveActorA(float DeltaTime);
	virtual void Tick(float DeltaTime) override;
	float RanSpeed;
	float RanSpin;

	float MoveSpeed;
	float RotationSpeed;

	
};
