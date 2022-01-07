/*
MIT License

Copyright (c) 2022 Ducktape

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef DISTANCEJOINT2D_H
#define DISTANCEJOINT2D_H

#include <Ducktape/engine/scripts.h>
#include <box2d/box2d.h>
#include <Ducktape/physics/rigidbody.h>
#include <Ducktape/engine/entity.h>
#include <Ducktape/physics/physics.h>

namespace DT
{
	class DistanceJoint2D : public PhysicsScript
	{
	private:
		b2DistanceJoint* joint;
		Rigidbody2D* rb;
		Rigidbody2D* connectedRigidbody = nullptr;

	public:
		DistanceJoint2D();
		
		void Update();
		void OnDestroy();

		Vector2 GetAnchorA();
		Vector2 GetAnchorB();
		Rigidbody2D* GetConnectedRigidbody();
		void SetConnectedRigidbody(Rigidbody2D* rb);
		float GetLength();
		void SetLength(float length);
		float GetMinLength();
		void SetMinLength(float minLength);
		float GetMaxLength();
		void SetMaxLength(float maxLength);
		float GetCurrentLength();
		float GetStiffness();
		void SetStiffness(float stiffness);
		float GetDamping();
		void SetDamping(float damping);
	};
}

#endif