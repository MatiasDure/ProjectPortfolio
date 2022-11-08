// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Target.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PersonalPortfolioProjectile.h"
#include "PersonalPortfolioGameMode.h"
#include "Kismet/Gameplaystatics.h"
#include "PersonalPortfolioCharacter.h"

// Sets default values
ACPP_Target::ACPP_Target()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//root object
	rootMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("rootMesh");
	SetRootComponent(rootMeshComponent);
	rootMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//collision boxes
	bodyCol = CreateDefaultSubobject<UBoxComponent>("bodyCollision");
	headCol = CreateDefaultSubobject<UBoxComponent>("headCollision");
	bodyCol->SetupAttachment(rootMeshComponent);
	headCol->SetupAttachment(rootMeshComponent);
}

// Called when the game starts or when spawned
void ACPP_Target::BeginPlay()
{
	Super::BeginPlay();

	player = Cast<APersonalPortfolioCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (bodyCol && headCol)
	{
		bodyCol->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Target::OnColliderOverlap);
		headCol->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Target::OnColliderOverlap);
	}
	
}

// Called every frame
void ACPP_Target::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Target::OnColliderOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	APersonalPortfolioProjectile* bullet = Cast<APersonalPortfolioProjectile>(OtherActor);
	
	//checking if other actor was cast to projectile
	if (bullet != nullptr)
	{
		//Getting the overlapped component
		UPrimitiveComponent* currentComp = SweepResult.GetComponent();
		if (currentComp == this->headCol)
		{
			check(player)
			player->IncreasePoints(headPoints);
			UGameplayStatics::PlaySound2D(this, headHit, 0.5f);
		}
		else if (currentComp == this->bodyCol)
		{
			check(player)
			player->IncreasePoints(bodyPoints);
			UGameplayStatics::PlaySound2D(this, bodyHit, 0.5f);
		}
	}
}

