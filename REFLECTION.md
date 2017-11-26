# Reflection

[//]: # (Image References)
[i]: ./plots/p_0.1_d_1.7_i_0.005.png "PID"
[d]: ./plots/p_0.1_d_1.7_i_.png "PD"
[p]: ./plots/p_0.1_d__i_.png "P only"

# Effects of the PID parameters

## Proportional
The P (proportional) parameter applies a steering angle that is proportional to the negative cross track error (the input value).
This means the larger the deviation from the ideal trajectory, the larger the opposed steering command becomes.
As we can see in the plot, this will lead to oscillations and overshooting of the cross track error, eventually (soon) leading to the car driving off-road.
![P error plot][p]

## Derivative
The D (derivative) parameter applies a steering angle that is proportional to the derivative of the steering angle.
If the steering angle changes rapidly, this term counteracts the tendency of the P parameter to overshoot.
As can be seen on the plot, the oscillations are greatly reduced and the car stays on the lane, but the cross track error also does not quite approach zero anymore.
![PD error plot][d]

## Integral
The I (integral) parameter applies a steering angle that is proportional to the integrated cross track error.
This leads the error to approach zero again, by increasing the "weight" of this parameter, the longer the error is different from zero.
The result of adding this parameter can be seen in the plot below.
![PID error plot][i]

# Finding the parameters
For finding the parameters, I followed a manual approach.
First, I set the throttle to double the original value, 0.6, so that the car would go a little faster.

The executable takes command line parameters corresponding to the P,D and I values.
Beginning with only the P value, I added in the D component and adapted the parameters to show as little oscillations as possbile.
The same was also done after the addition of the I parameter.

The final values chosen are P=0.1, I=0.005, D=1.7.
