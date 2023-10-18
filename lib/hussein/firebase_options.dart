// File generated by FlutterFire CLI.
// ignore_for_file: lines_longer_than_80_chars, avoid_classes_with_only_static_members
import 'package:firebase_core/firebase_core.dart' show FirebaseOptions;
import 'package:flutter/foundation.dart'
    show defaultTargetPlatform, kIsWeb, TargetPlatform;

/// Default [FirebaseOptions] for use with your Firebase apps.
///
/// Example:
/// ```dart
/// import 'firebase_options.dart';
/// // ...
/// await Firebase.initializeApp(
///   options: DefaultFirebaseOptions.currentPlatform,
/// );
/// ```
class DefaultFirebaseOptions {
  static FirebaseOptions get currentPlatform {
    if (kIsWeb) {
      return web;
    }
    switch (defaultTargetPlatform) {
      case TargetPlatform.android:
        return android;
      case TargetPlatform.iOS:
        return ios;
      case TargetPlatform.macOS:
        return macos;
      case TargetPlatform.windows:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for windows - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      case TargetPlatform.linux:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for linux - '
          'you can reconfigure this by running the FlutterFire CLI again.',
        );
      default:
        throw UnsupportedError(
          'DefaultFirebaseOptions are not supported for this platform.',
        );
    }
  }

  static const FirebaseOptions web = FirebaseOptions(
    apiKey: 'AIzaSyA05Putr1mYPpeP_a-esU2a5Q1SIvmQ_Tk',
    appId: '1:295068575764:web:f6b6560074230033539f01',
    messagingSenderId: '295068575764',
    projectId: 'iotfinalproject-d6593',
    authDomain: 'iotfinalproject-d6593.firebaseapp.com',
    storageBucket: 'iotfinalproject-d6593.appspot.com',
    measurementId: 'G-M009GP1DTC',
  );

  static const FirebaseOptions android = FirebaseOptions(
    apiKey: 'AIzaSyC9DxXvkY_zoryAy_DWbN2gSZKxIo3ygBI',
    appId: '1:295068575764:android:50814ab9b6288dab539f01',
    messagingSenderId: '295068575764',
    projectId: 'iotfinalproject-d6593',
    storageBucket: 'iotfinalproject-d6593.appspot.com',
  );

  static const FirebaseOptions ios = FirebaseOptions(
    apiKey: 'AIzaSyA3o94CH9cYNrtBiLsjaCWJv7c5dUWYGvw',
    appId: '1:295068575764:ios:559768cd2cb80557539f01',
    messagingSenderId: '295068575764',
    projectId: 'iotfinalproject-d6593',
    storageBucket: 'iotfinalproject-d6593.appspot.com',
    iosClientId: '295068575764-7gjmticokr3cnhdm8c521anrkrmv5cfl.apps.googleusercontent.com',
    iosBundleId: 'com.example.gradutionproject',
  );

  static const FirebaseOptions macos = FirebaseOptions(
    apiKey: 'AIzaSyA3o94CH9cYNrtBiLsjaCWJv7c5dUWYGvw',
    appId: '1:295068575764:ios:559768cd2cb80557539f01',
    messagingSenderId: '295068575764',
    projectId: 'iotfinalproject-d6593',
    storageBucket: 'iotfinalproject-d6593.appspot.com',
    iosClientId: '295068575764-7gjmticokr3cnhdm8c521anrkrmv5cfl.apps.googleusercontent.com',
    iosBundleId: 'com.example.gradutionproject',
  );
}
