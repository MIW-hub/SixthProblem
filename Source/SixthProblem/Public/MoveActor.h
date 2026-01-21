// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MoveActor.generated.h"

UCLASS()
class SIXTHPROBLEM_API AMoveActor : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move");
	float MaxRange = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move");
	float MinRange = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move");
	float MoveSpeed = 5.0f;
	FVector StartLocation;
	FVector CurrentLocation; // 처음 시작 위치 저장용
	FVector MoveDirection;
	bool Returning = false; // 현재 돌아오는 중인지 체크
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
