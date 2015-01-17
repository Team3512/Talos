//=============================================================================
//File Name: BezierTrapezoidProfile.hpp
//Description: Provides trapezoidal velocity control and follows a given Bézier
//             curve
//Author: FRC Team 3512, Spartatroniks
//=============================================================================

/* Implementation of trapezoid motion profile translated to C++; base Java code
 * courtesy of FRC Team 254; modifications for Bézier curve by FRC Team 3512.
 */

/* Constant acceleration until target (max) velocity is reached, sets
 * acceleration to zero for a calculated time, then decelerates at a constant
 * acceleration with a slope equal to the negative slope of the initial
 * acceleration.
 */

#ifndef BEZIER_TRAPEZOID_PROFILE_HPP
#define BEZIER_TRAPEZOID_PROFILE_HPP

#include "TrapezoidProfile.hpp"
#include "BezierCurve.hpp"

class BezierTrapezoidProfile : public TrapezoidProfile {
public:
    BezierTrapezoidProfile( double maxV , double timeToMaxV );
    virtual ~BezierTrapezoidProfile();

    /* curTime is current time
     *
     * If distance:
     *     curSource is current position (not used)
     *
     * If velocity:
     *     curSource is current velocity (not used)
     *
     * returns updated uncompensated setpoint (see double getMidSetpoint())
     */
    double updateSetpoint( double curTime , double curSource = 0.0 );

    /* Returns uncompensated setpoint for use in control of systems other than
     * the drive train
     */
    double getMidSetpoint() const;

    double getLeftSetpoint() const;
    double getRightSetpoint() const;

    /* goal is a Bézier curve for robot to follow
     * curSource is the current position
     * t initializes m_lastTime
     *
     * returns starting setpoint
     */
    double setGoal( const BezierCurve& curve , double t );

    // Sets distance between two sides of drive train
    void setWidth( double width );

private:
    // The robot follows this by turning in the motion profile
    BezierCurve m_curve;
    double m_width;

    // Collection of setpoints
    double m_leftSetpoint;
    double m_rightSetpoint;

    /* goal is a distance to which to travel
     * curSource is the current position
     * t initializes m_lastTime
     */
    double setGoal( double t , double goal , double curSource = 0.0 );

    /* t is time elapsed since start of motion
     * v is current setpoint velocity of middle of robot
     */
    double getLeftVelocity( double t , double v ) const;
    double getRightVelocity( double t , double v ) const;
};

#endif // BEZIER_TRAPEZOID_PROFILE_HPP