// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Target.generated.h"

UCLASS()
class PERSONALPORTFOLIO_API ACPP_Target : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Target();

	UPROPERTY(EditAnywhere, Category = "MESH")
		class UStaticMeshComponent* rootMeshComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Collision")
		class UBoxComponent* headCol = nullptr;

	UPROPERTY(EditAnywhere, Category = "Collision")
		class UBoxComponent* bodyCol = nullptr;

	UPROPERTY(EditAnywhere, Category = "Player")
		class APersonalPortfolioCharacter* player = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* headHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* bodyHit;

	UPROPERTY(EditAnywhere, Category = "Score")
		int headPoints = 15;
	UPROPERTY(EditAnywhere, Category = "Score")
		int bodyPoints = 10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnColliderOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
