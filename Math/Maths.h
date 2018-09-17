#pragma once

float Approach(float goal, float current, float dt)
{
    const auto diff = goal - current;

    if (diff > dt) {
        return current + dt;
    }

    if (diff < -dt) {
        return current - dt;
    }

    return goal;
}
