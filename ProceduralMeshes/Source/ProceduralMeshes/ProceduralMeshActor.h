#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshActor.generated.h"

struct FCubeFace
{
	TArray<FVector*> Vertices;
	
	FCubeFace() {};

	FCubeFace(FVector* One, FVector* Two, FVector* Three, FVector* Four)
	{
		Vertices.Add(One);
		Vertices.Add(Two);
		Vertices.Add(Three);
		Vertices.Add(Four);
	}
};

UCLASS()
class PROCEDURALMESHES_API AProceduralMeshActor : public AActor
{
	GENERATED_BODY()

public:

	AProceduralMeshActor();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UProceduralMeshComponent* ProceduralMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class  UParticleSystemComponent* SelectedVertexEffect;

	FVector* SelectedVertex;

	/* Vertices needed to generate a procedural cube mesh */
	FVector LowerBackLeft;
	FVector UpperBackLeft;
	FVector LowerBackRight;
	FVector UpperBackRight;
	FVector LowerFrontLeft;
	FVector UpperFrontLeft;
	FVector UpperFrontRight;
	FVector LowerFrontRight;

	FCubeFace FaceTop;
	FCubeFace FaceBot;
	FCubeFace FaceLeft;
	FCubeFace FaceRight;

	/* Array containing all vertices of our procedural mesh */
	TArray<FVector> Vertices;

	/* Array containing all triangles needed to draw our procedural mesh */
	TArray<int32> Triangles;

	/* Creates a triangle to connect three vertices (REMEBER TO ADD THEM COUNTER_CLOCKWISE) */
	void GenerateTriangle(int32 Vertex1, int32 Vertex2, int32 Vertex3);

	void GenerateProceduralMesh();

public:

	virtual void Tick(float DeltaTime) override;

private:
	
	float m_fAccumulator;
	
	
};
