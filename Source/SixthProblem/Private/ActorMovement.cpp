// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorMovement.h"
#include "SpawnMoveActor.h"
// Sets default values
AActorMovement::AActorMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActorRotaion = FRotator::ZeroRotator;
	CurrentLocation = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AActorMovement::BeginPlay()
{
	Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(
        MyTimerHandle,
        this,
        &AActorMovement::SpawnActorFuntion,
        1.0f,
        true
    );
    CurrentLocation = GetActorLocation();
}

// Called every frame
void AActorMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorMovement::StopSpawning()
{
	GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
}


void AActorMovement::SpawnActorFuntion()
{
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	FVector Center = GetActorLocation();


	float RanX = FMath::FRandRange(0.0f, 500.0f);
	float RanY = FMath::FRandRange(0.0f, 500.0f);


	FVector SpawnLocation = Center + FVector(RanX, RanY, 0.0f);

	ASpawnMoveActor* NewActor = GetWorld()->SpawnActor<ASpawnMoveActor>(
		SpawnActorA,
		SpawnLocation,
		ActorRotaion,
		Params
	);

	if (NewActor)
	{
		// 로그 3: 성공적으로 스폰되었는지 확인
		UE_LOG(LogTemp, Warning, TEXT("Spawn Success: %s"), *NewActor->GetName());
	}

	if (SpawnActorA == nullptr) return;

	UE_LOG(LogTemp, Warning, TEXT("Spawn Function Called!"));

	if (SpawnActorA == nullptr)
	{
		// 로그 2: 에디터에서 클래스 할당을 깜빡했는지 확인
		UE_LOG(LogTemp, Error, TEXT("SpawnActorA is NULL! Check your Editor Details!"));
		return;
	}

	if (NewActor)
	{// 여기서 매니저가 가진 속도 값을 전달
		NewActor->SetSpeed(ReturnSpeed);
		NewActor->SetSpin(ReturnRotate);

		UE_LOG(LogTemp, Warning, TEXT("Spawn Success: %s, Speed: %f"), *NewActor->GetName(), NewActor->MoveSpeed);
	}

	

}
