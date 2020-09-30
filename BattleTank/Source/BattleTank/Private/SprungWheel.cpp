// Copyright AbraceTI Ltd.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\SprungWheel.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Actor.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\StaticMeshComponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"


// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Check Tick Group 
	PrimaryActorTick.TickGroup = TG_PostPhysics;



	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("MassWheelConstraint"));
	SetRootComponent(MassWheelConstraint);
		
	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axle"));
	Axle->SetupAttachment(MassWheelConstraint);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axle);
	
	AxleWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxleWheelConstraint"));
	AxleWheelConstraint->SetupAttachment(Axle);

}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
	//UE_LOG(LogTemp, Warning, TEXT("null"));
	
	Wheel->SetNotifyRigidBodyCollision(true);//Always receive those OnHit

	Wheel->OnComponentHit.AddDynamic(this, &ASprungWheel::OnHit);

	SetupConstraint();
}

void ASprungWheel::SetupConstraint()
{
	if (!GetAttachParentActor()) return;

	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());

	if (!BodyRoot) return;
	MassWheelConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axle, NAME_None);
	AxleWheelConstraint->SetConstrainedComponents(Axle, NAME_None, Wheel, NAME_None);

}


// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	
	//UE_LOG(LogTemp, Warning, TEXT("Tick %f"), GetWorld()->GetTimeSeconds());

	//Double Check Tick Group 
	if (GetWorld()->TickGroup == TG_PostPhysics) 
	{
		TotalForceMagnitudeThisFrame = 0;
	}
	
}

void ASprungWheel::AddDrivingForce(float ForceMagnitude)
{	
	//Do proper addition within the frame, get the total force magnitude at the end.
	//without tank wont be able to steer

	TotalForceMagnitudeThisFrame += ForceMagnitude;
		
}

void ASprungWheel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("OnHit %f"), GetWorld()->GetTimeSeconds() );
	ApplyForce();
}

void ASprungWheel::ApplyForce()
{
	//Get the direction to this force
	Wheel->AddForce( Axle->GetForwardVector() * TotalForceMagnitudeThisFrame );

}



